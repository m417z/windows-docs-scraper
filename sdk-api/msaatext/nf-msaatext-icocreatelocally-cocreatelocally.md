# ICoCreateLocally::CoCreateLocally

## Description

Clients call **ICoCreateLocally::CoCreateLocally** to create a helper object in the same context as the server object. This allows clients to increase performance because they are running in the server application.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `rclsid` [in]

Type: **REFCLSID**

Class identifier of the object to be created locally.

### `dwClsContext` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Context in which the helper object should run. This is usually CLSCTX_INPROC_SERVER.

### `riid` [in]

Type: **REFIID**

The desired interface identifier (IID).

### `punk` [out]

Type: **IUnknown***

Interface pointer to the desired interface identifier (from *riid*).

### `riidParam` [in]

Type: **REFIID**

An optional interface parameter that is passed to the new helper object. This parameter specifies an interface identifier.

### `punkParam` [in]

Type: **IUnknown***

An optional interface parameter that is passed to the new helper object. This parameter specifies the interface pointer.

### `varParam` [in]

Type: **VARIANT**

An optional interface parameter that is passed to the new helper object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns the following value or another standard COM error code.

| Error | Description |
| --- | --- |
| **E_ACCESSDENIED** | The client does not have sufficient permissions to create this object in the server process. |