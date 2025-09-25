# IOCTL_NFCSE_SET_CARD_EMULATION_MODE IOCTL

## Description

The **IOCTL_NFCSE_SET_CARD_EMULATION_MODE**
control code sets whether the specified secure element is exposed in card emulation mode. When a secure element is “exposed” as card emulation, it means when the device is brought to an external reader that secure element can be accessed by the reader. The IOCTL is issued on a file handle opened with a relative filename ‘SEManage’. The driver MUST grant exclusive access to the client to manage card emulation mode, that is, subsequent calls to open a file handle using relative filename ‘SEManage’ will fail with STATUS_ACCESS_DENIED until the client with exclusive access closes its file handle.

## Parameters

### Major code

### Input buffer

 [SECURE_ELEMENT_SET_CARD_EMULATION_MODE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_set_card_emulation_mode_info) structure.

### Input buffer length

### Output buffer

None

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | If the secure element GUID is invalid or output buffer is non-zero. |
| **STATUS_INVALID_DEVICE_STATE** | If the IOCTL is sent on a handle other than with the relative name 'SEManage'. |

## Remarks

The following are requirements that the driver must adhere to.

* This IOCTL must be called on a handle that has an SEEvents relative file name; otherwise, the driver returns STATUS_INVALID_DEVICE_STATE.
* If card emulation mode is set to EmulationOff for all the secure elements that are attached to the NFC controller, the emulation mode of the polling loop must be disabled. If proximity features are also disabled, the driver should transition to a low power mode.
* If card emulation mode is set to a value other than EmulationOff, then the driver must continue to be in the D0 state and the emulation mode of the polling loop should be enabled (detectable to external readers).
* When the SEManage opened file handle is closed, the driver must set the card emulation mode settings of all secure elements to be EmulationOff except when the last set card emulation mode state is EmulationOnPowerIndependent. If the last set card emulation mode state is EmulationOnPowerIndependent, the driver must remain with the card emulation mode setting to On with the PbF option for the specific secure elements.
* The driver must grant exclusive access to the client to manage card emulation mode. Subsequent calls to open a file handle using relative filename SEManage would fail with STATUS_ACCESS_DENIED until the client with exclusive access closes its file handle.