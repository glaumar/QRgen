import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 800
    title: qsTr("QRgen")

    Column {
        anchors.centerIn: parent
        spacing: 20
        Image{
            source: "image://QZXing/encode/" + inputField.text
            sourceSize.width: 500
            sourceSize.height: 500
        }

        ScrollView {
            width: 500
            height: 200
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
