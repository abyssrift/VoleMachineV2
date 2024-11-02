#include <QWidget>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QMessageBox>

class FileDropWidget : public QWidget {
    Q_OBJECT

public:
    explicit FileDropWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setAcceptDrops(true);  // Enable drop events for this widget
    }

protected:
    void dragEnterEvent(QDragEnterEvent *event) override {
        // Accept only if the dragged data has URLs (files)
        if (event->mimeData()->hasUrls()) {
            event->acceptProposedAction();
        }
    }

    void dropEvent(QDropEvent *event) override {
        // Get the URLs (file paths) from the mime data
        const QMimeData *mimeData = event->mimeData();

        if (mimeData->hasUrls()) {
            QStringList filePaths;
            foreach (const QUrl &url, mimeData->urls()) {
                QString filePath = url.toLocalFile();
                filePaths << filePath;
            }

            // Example: Show the paths of dropped files in a message box
            QMessageBox::information(this, "Dropped Files", filePaths.join("\n"));

            // You can handle the files as needed, e.g., read contents, open, etc.
        }
    }
};
