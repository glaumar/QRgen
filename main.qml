import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 800
    height: 800
    title: qsTr("QRgen")

    // TODO:
    // - export
    // - import
    // - limit input length
    Column {
        width: Math.max(300, parent.width * 0.9)
        height: Math.max(300, parent.height * 0.9)

        anchors.centerIn: parent
        spacing: 20
        Image {
            id: qrImg
            width: height
            height: parent.height - 150
            anchors.horizontalCenter: parent.horizontalCenter
            source: "image://QZXing/encode/" + inputField.text + "?correctionLevel="
                    + correctionLevel.currentText + "&format=qrcode"
            sourceSize.width: 960
            sourceSize.height: 960
        }

        RowLayout {
            width: qrImg.width
            anchors.horizontalCenter: parent.horizontalCenter

            spacing: 10
            Button {
                text: "Import"
                Layout.fillWidth: true
            }
            Button {
                text: "Export"
                Layout.fillWidth: true
            }

            ComboBox {
                id: correctionLevel
                displayText: "Level: " + currentText
                model: ["H", "Q", "M", "L"]
            }
        }

        ScrollView {
            width: qrImg.width
            anchors.horizontalCenter: parent.horizontalCenter
            height: 100
            TextArea {
                id: inputField
                implicitHeight: parent.height
                implicitWidth: parent.width
                text: "Hello world!"

                wrapMode: TextEdit.WrapAnywhere
                textFormat: TextEdit.PlainText
                selectByMouse: true
                mouseSelectionMode: TextEdit.SelectCharacters
                selectionColor: "#3daee9"
            }

            background: Rectangle {
                implicitHeight: parent.height
                implicitWidth: parent.width
                border.width: 1
            }
        }
    }
}
