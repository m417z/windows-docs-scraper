# IWDFDeviceInitialize::RetrieveDeviceInstanceId

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [RetrieveDeviceInstanceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedeviceinstanceid) method retrieves the identifier of an instance of a device.

## Parameters

### `Buffer` [out, optional]

A pointer to a buffer that receives a **NULL**-terminated string that represents the identifier of an instance of a device if the supplied buffer is non-**NULL** and [RetrieveDeviceInstanceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedeviceinstanceid) is successful.

### `pdwSizeInChars` [in, out]

A pointer to a variable that receives the number of characters, including the **NULL** character, in the string that *Buffer* points to.

If *Buffer* is **NULL**, the value that the driver supplies is zero. The framework then returns the size, in characters, that is required for the identifier string.

If *Buffer* is non-**NULL**, the framework returns the size, in characters, of the identifier string.

## Return value

[RetrieveDeviceInstanceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedeviceinstanceid) returns S_OK for the following scenarios:

* The buffer that the *Buffer* parameter pointed to was non-**NULL** and large enough to hold the identifier string, including the **NULL** character, and the framework successfully copied the string into the supplied buffer and set the variable that was pointed to by the *pdwSizeInChars* parameter to the number of characters in the string.
* The buffer at *Buffer* was **NULL**, the driver preset the variable at *pdwSizeInChars* to 0, and the framework set the variable at *pdwSizeInChars* to the number of characters that are required for the string.

[RetrieveDeviceInstanceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedeviceinstanceid) returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) to indicate that the supplied buffer is non-**NULL** and does not contain enough space to hold the identifier string. The framework sets the variable at *pdwSizeInChars* to the number of characters that are required for the string.

[RetrieveDeviceInstanceId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedeviceinstanceid) might also return other HRESULT values.

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)