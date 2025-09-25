# HidRegisterMinidriver function

## Description

The **HidRegisterMinidriver** routine is called by HID minidrivers, during their initialization, to register with the HID class driver.

## Parameters

### `MinidriverRegistration` [in]

Pointer to a caller-allocated buffer that contains an initialized [HID_MINIDRIVER_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ns-hidport-_hid_minidriver_registration) structure for the minidriver.

## Return value

**HidRegisterMinidriver** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that the routine completed without error and the minidriver is now registered with the HID class driver. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that there was insufficient memory for the system to register the minidriver. |
| **STATUS_REVISION_MISMATCH** | Indicates that the HID revision number provided in *MinidriverRegistration->*Revision is not supported by this version of the HID class driver. |

## Remarks

Before calling this routine, HID minidrivers must initialize all members of the HID_MINIDRIVER_REGISTRATION structure that is provided at *MinidriverRegistration*. For information about these members, see [HID_MINIDRIVER_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ns-hidport-_hid_minidriver_registration).

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HID_MINIDRIVER_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ns-hidport-_hid_minidriver_registration)