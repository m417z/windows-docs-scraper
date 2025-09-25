# WCN_VALUE_TYPE_PRIMARY_DEVICE_TYPE structure

## Description

The **WCN_VALUE_TYPE_PRIMARY_DEVICE_TYPE** structure contains information that identifies the device type by category, sub-category, and a manufacturer specific OUI (Organization ID).

## Members

### `Category`

Specifies the primary device type category. This data is supplied in network byte order.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_CATEGORY_COMPUTER**<br><br>0x1 | Indicates a computer. |
| **WCN_VALUE_DT_CATEGORY_INPUT_DEVICE**<br><br>0x2 | Indicates an input device. |
| **WCN_VALUE_DT_CATEGORY_PRINTER**<br><br>0x3 | Indicates a printer. |
| **WCN_VALUE_DT_CATEGORY_CAMERA**<br><br>0x4 | Indicates a camera. |
| **WCN_VALUE_DT_CATEGORY_STORAGE**<br><br>0x5 | Indicates a storage device. |
| **WCN_VALUE_DT_CATEGORY_NETWORK_INFRASTRUCTURE**<br><br>0x6 | Indicates a network. |
| **WCN_VALUE_DT_CATEGORY_DISPLAY**<br><br>0x7 | Indicates a display. |
| **WCN_VALUE_DT_CATEGORY_MULTIMEDIA_DEVICE**<br><br>0x8 | Indicates a multimedia device. |
| **WCN_VALUE_DT_CATEGORY_GAMING_DEVICE**<br><br>0x9 | Indicates a gaming device. |
| **WCN_VALUE_DT_CATEGORY_TELEPHONE**<br><br>0xa | Indicates a telephone. |
| **WCN_VALUE_DT_CATEGORY_AUDIO_DEVICE**<br><br>0xb | Indicates an audio device.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_CATEGORY_OTHER**<br><br>0xff | Indicates an unspecified device.<br><br>**Note** Only available in Windows 8. |

### `SubCategoryOUI`

Specifies the unique manufacturer OUI associated with the device.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_WIFI_OUI**<br><br>0x50f204 | Indicates the specific manufacturer Organization ID (OUI) for a wireless device. |

### `SubCategory`

Specifies the primary device type sub-category. This data is supplied in network byte order. If **SubCategoryOUI** is equal to **WCN_VALUE_DT_SUBTYPE_WIFI_OUI**, then any of the values below are valid. Otherwise, the SubCategory has been defined by the vendor.

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_COMPUTER**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_PC**<br><br>0x1 | Indicates a personal computer. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_SERVER**<br><br>0x2 | Indicates a server. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_MEDIACENTER**<br><br>0x3 | Indicates a media center.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_ULTRAMOBILEPC**<br><br>0x4 | Indicates an Ultra-Mobile PC.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_NOTEBOOK**<br><br>0x5 | Indicates a notebook computer.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_DESKTOP**<br><br>0x6 | Indicates a desktop computer.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_MID**<br><br>0x7 | Indicates a mobile Internet device.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_COMPUTER_NETBOOK**<br><br>0x8 | Indicates a netbook.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_INPUT_DEVICE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_KEYBOARD**<br><br>0x1 | Indicates a keyboard.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_MOUSE**<br><br>0x2 | Indicates a mouse.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_JOYSTICK**<br><br>0x3 | Indicates a joystick.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_TRACKBALL**<br><br>0x4 | Indicates a trackball.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_GAMECONTROLLER**<br><br>0x5 | Indicates a game controller.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_REMOTE**<br><br>0x6 | Indicates a remote control.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_TOUCHSCREEN**<br><br>0x7 | Indicates a touch screen.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_BIOMETRICREADER**<br><br>0x8 | Indicates a biometric reader.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE_BARCODEREADER**<br><br>0x9 | Indicates a barcode reader.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_PRINTER**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_PRINTER_PRINTER**<br><br>0x1 | Indicates a printer. |
| **WCN_VALUE_DT_SUBTYPE_PRINTER_SCANNER**<br><br>0x2 | Indicates a scanner. |
| **WCN_VALUE_DT_SUBTYPE_PRINTER_FAX**<br><br>0x3 | Indicates a fax machine.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_PRINTER_COPIER**<br><br>0x4 | Indicates a copier.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_PRINTER_ALLINONE**<br><br>0x4 | Indicates an all-in-one printer.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_CAMERA**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_CAMERA_STILL_CAMERA**<br><br>0x1 | Indicates a still-shot camera. |
| **WCN_VALUE_DT_SUBTYPE_CAMERA_VIDEO_CAMERA**<br><br>0x2 | Indicates a video camera.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_CAMERA_WEB_CAMERA**<br><br>0x3 | Indicates a web camera.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_CAMERA_SECURITY_CAMERA**<br><br>0x4 | Indicates a security camera.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_NETWORK_STORAGE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_STORAGE_NAS**<br><br>0x1 | Indicates a network storage device. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_NETWORK_INFRASTRUCTURE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE_AP**<br><br>0x1 | Indicates an access point. |
| **WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE_ROUTER**<br><br>0x2 | Indicates a router. |
| **WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE_SWITCH**<br><br>0x3 | Indicates a switch. |
| **WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE_GATEWAY**<br><br>0x4 | Indicates a gateway.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE_BRIDGE**<br><br>0x5 | Indicates a bridge.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_DISPLAY**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_DISPLAY_TELEVISION**<br><br>0x1 | Indicates a television. |
| **WCN_VALUE_DT_SUBTYPE_DISPLAY_PICTURE_FRAME**<br><br>0x2 | Indicates an electronic picture frame. |
| **WCN_VALUE_DT_SUBTYPE_DISPLAY_PROJECTOR**<br><br>0x3 | Indicates a digital projector. |
| **WCN_VALUE_DT_SUBTYPE_DISPLAY_MONITOR**<br><br>0x4 | Indicates a monitor.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_MULTIMEDIA_DEVICE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_DAR**<br><br>0x1 | Indicates a digital audio recorder. |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_PVR**<br><br>0x2 | Indicates a personal video recorder. |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_MCX**<br><br>0x3 | Indicates a Yamaha Digital Multimedia Receiver. |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_SETTOPBOX**<br><br>0x4 | Indicates a set-top box.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_MEDIA_SERVER_ADAPT_EXT**<br><br>0x5 | Indicates a media server, media adapter, or media extender.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE_PVP**<br><br>0x6 | Indicates a portable video player.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_GAMING_DEVICE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE_XBOX**<br><br>0x1 | Indicates a Microsoft XBOX console. |
| **WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE_XBOX360**<br><br>0x2 | Indicates a Microsoft XBOX 360 console. |
| **WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE_PLAYSTATION**<br><br>0x3 | Indicates a Sony Playstation 3. |
| **WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE_CONSOLE_ADAPT**<br><br>0x4 | Indicates a game console adapter.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE_PORTABLE**<br><br>0x5 | Indicates a portable gaming device.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_TELEPHONE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_TELEPHONE_WINDOWS_MOBILE**<br><br>0x1 | Indicates a Windows Mobile device. |
| **WCN_VALUE_DT_SUBTYPE_TELEPHONE_PHONE_SINGLEMODE**<br><br>0x2 | Indicates a single-mode phone.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_TELEPHONE_PHONE_DUALMODE**<br><br>0x3 | Indicates a dual-mode phone.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_TELEPHONE_PHONE_SMARTPHONE_SINGLEMODE**<br><br>0x4 | Indicates a single-mode smartphone.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_TELEPHONE_PHONE_SMARTPHONE_DUALMODE**<br><br>0x2 | Indicates a dual-mode smartphone.<br><br>**Note** Only available in Windows 8. |

The following values are possible when the **Category** member is set to **WCN_VALUE_DT_CATEGORY_AUDIO_DEVICE**.

| Value | Meaning |
| --- | --- |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_TUNER_RECEIVER**<br><br>0x1 | Indicates an audio tuner/receiver.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_SPEAKERS**<br><br>0x2 | Indicates speakers.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_PMP**<br><br>0x2 | Indicates a personal media player.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_HEADSET**<br><br>0x2 | Indicates a headset.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_HEADPHONES**<br><br>0x2 | Indicates headphones.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_MICROPHONE**<br><br>0x2 | Indicates a microphone.<br><br>**Note** Only available in Windows 8. |
| **WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE_HOMETHEATER**<br><br>0x2 | Indicates a home theater system.<br><br>**Note** Only available in Windows 8. |