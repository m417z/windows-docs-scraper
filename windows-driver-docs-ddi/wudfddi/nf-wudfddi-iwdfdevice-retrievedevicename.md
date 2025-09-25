# IWDFDevice::RetrieveDeviceName

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveDeviceName** method retrieves the name of an underlying kernel-mode device.

## Parameters

### `pDeviceName` [out]

A pointer to a buffer that receives a **NULL**-terminated string that represents the name of the underlying kernel-mode device, if the buffer is non-**NULL** and **RetrieveDeviceName** is successful.

### `pdwDeviceNameLength` [in, out]

A pointer to a variable that receives the number of characters, including the **NULL** character, in the device name.

If the buffer at *pDeviceName* is **NULL**, the value that the driver supplies is zero. The framework then returns the size, in characters, that is required for the device name string.

If the buffer at *pDeviceName* is non-**NULL**, the framework returns the size, in characters, of the device name string.

## Return value

**RetrieveDeviceName** returns S_OK for the following scenarios:

* The buffer that the *pDeviceName* parameter pointed to was non-**NULL** and large enough to hold the name string, including the **NULL** character, and the framework successfully copied the string into the supplied buffer and set the variable that is pointed to by *pdwDeviceNameLength* to the number of characters in the string.
* The buffer at *pDeviceName* was **NULL**, the driver preset the variable at *pdwDeviceNameLength* to 0, and the framework set the variable at *pdwDeviceNameLength* to the number of characters that were required for the string.

**RetrieveDeviceName** returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) to indicate that the supplied buffer was non-**NULL** and did not contain enough space to hold the device name. The framework sets the variable at *pdwDeviceNameLength* to the number of characters that are required for the string.

**RetrieveDeviceName** might also return other HRESULT values.

## Remarks

The device name is not the physical device object (PDO) name. Instead, the device name is the name of the reflector. The driver must target all I/O to this device object.

#### Examples

The following code example shows how to retrieve the name of an underlying kernel-mode device.

```
    PWSTR deviceName = NULL;
    DWORD deviceNameCch = 0;
    HRESULT hr;
    //
    // Get the length of the device name to allocate a buffer
    //
    hr = m_FxDevice->RetrieveDeviceName(NULL, &deviceNameCch);
    //
    // Allocate the buffer
    //
    deviceName = new WCHAR[deviceNameCch];

    if (deviceName == NULL) {
        hr = E_OUTOFMEMORY;
        goto Exit1;
    }
    //
    // Get the device name
    //
    hr = m_FxDevice->RetrieveDeviceName(deviceName,
                                        &deviceNameCch);

    // Open the device and get the handle

    m_Handle = CreateFile(deviceName,
                         (GENERIC_READ | GENERIC_WRITE),
                         0,
                         NULL,
                         OPEN_EXISTING,
                         FILE_FLAG_OVERLAPPED,
                         NULL);
```

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)