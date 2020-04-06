import QtQuick 2.12
import QtQuick.Window 2.12
import RolesSqlModel 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")



    Rectangle {
        width: 500
        height: 500
        MouseArea {
            anchors.fill: parent
            Text {
                id: text1
  anchors.verticalCenterOffset: 20
  anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Testing")
                font.pixelSize: 12
            }
            ListView {
                id: list_view1


                width: 500
                height: 500
                delegate: RolesItemDelegate {}
                model: Role{}
            }
        }

    }

}
