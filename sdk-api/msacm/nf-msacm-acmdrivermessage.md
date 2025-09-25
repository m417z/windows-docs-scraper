# acmDriverMessage function

## Description

The **acmDriverMessage** function sends a user-defined message to a given ACM driver instance.

## Parameters

### `had`

Handle to the ACM driver instance to which the message will be sent.

### `uMsg`

Message that the ACM driver must process. This message must be in the ACMDM_USER message range (above or equal to ACMDM_USER and less than ACMDM_RESERVED_LOW). The exceptions to this restriction are the ACMDM_DRIVER_ABOUT, [DRV_QUERYCONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-queryconfigure), and [DRV_CONFIGURE](https://learn.microsoft.com/windows/desktop/Multimedia/drv-configure) messages.

### `lParam1`

Message parameter.

### `lParam2`

Message parameter.

## Return value

The return value is specific to the user-defined ACM driver message specified by the uMsg parameter. However, possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | The *uMsg* parameter is not in the ACMDM_USER range. |
| **MMSYSERR_NOTSUPPORTED** | The ACM driver did not process the message. |

## Remarks

To display a custom About dialog box from an ACM driver, an application must send the ACMDM_DRIVER_ABOUT message to the driver. The *lParam1* parameter should be the handle of the owner window for the custom About dialog box, and *lParam2* must be set to zero. If the driver does not support a custom About dialog box, MMSYSERR_NOTSUPPORTED will be returned and it is the application's responsibility to display its own dialog box. For example, the Control Panel Sound Mapper option will display a default About dialog box based on the **ACMDRIVERDETAILS** structure when an ACM driver returns MMSYSERR_NOTSUPPORTED. An application can query a driver for custom About dialog box support without the dialog box being displayed by setting *lParam1* to –1L. If the driver supports a custom About dialog box, MMSYSERR_NOERROR will be returned. Otherwise, the return value is MMSYSERR_NOTSUPPORTED.

User-defined messages must be sent only to an ACM driver that specifically supports the messages. The caller should verify that the ACM driver is the correct driver by retrieving the driver details and checking the **wMid**, **wPid**, and **vdwDriver** members of the **ACMDRIVERDETAILS** structure.

Never send user-defined messages to an unknown ACM driver.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)