# IMMDevice::OpenPropertyStore

## Description

The **OpenPropertyStore** method retrieves an interface to the device's property store.

## Parameters

### `stgmAccess` [in]

The storage-access mode. This parameter specifies whether to open the property store in read mode, write mode, or read/write mode. Set this parameter to one of the following STGM constants:

STGM_READ

STGM_WRITE

STGM_READWRITE

The method permits a client running as an administrator to open a store for read-only, write-only, or read/write access. A client that is not running as an administrator is restricted to read-only access. For more information about STGM constants, see the Windows SDK documentation.

### `ppProperties` [out]

Pointer to a pointer variable into which the method writes the address of the **IPropertyStore** interface of the device's property store. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **OpenPropertyStore** call fails, **ppProperties* is **NULL**. For more information about **IPropertyStore**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *stgmAccess* is not a valid access mode. |
| **E_POINTER** | Parameter *ppProperties* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

In general, the properties in the device's property store are read-only for clients that do not perform administrative, system, or service functions.

For code examples that call the **OpenPropertyStore** method, see the following topics:

* [Device Properties](https://learn.microsoft.com/windows/desktop/CoreAudio/device-properties)
* [Device Roles for DirectSound Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/device-roles-for-directsound-applications)

## See also

[IMMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nn-mmdeviceapi-immdevice)