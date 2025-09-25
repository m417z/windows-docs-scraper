## Description

Opens the audio system effects default property store.

## Parameters

### `stgmAccess`

The storage-access mode. This parameter specifies whether to open the property store in read mode, write mode, or read/write mode. Set this parameter to one of the following STGM constants:

STGM_READ

STGM_WRITE

STGM_READWRITE

The method permits a client running as an administrator to open a store for read-only, write-only, or read/write access. A client that is not running as an administrator is restricted to read-only access.

### `propStore`

Receives a pointer to an [IPropertyStore](https://learn.microsoft.com/windows/win32/api/propsys/nn-propsys-ipropertystore) representing the default property store.

## Return value

Returns an HRESULT including, but not limited to the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| E_NOTFOUND | The call is attempting to open a property store that does not exist. See Remarks. |
| E_ACCESSDENIED | The caller was denied access for the specified *stgmAccess* value |

## Remarks

This method will only open existing property stores under the context registry keys. It will not create a new key if one is not present in the associated INF file. Attempting to access a property store that does not already exist will result in an E_NOTFOUND error.

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also