# IMbnPin::GetPinManager

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager).

## Parameters

### `pinManager` [out]

Pointer to the address of an [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to manage the PIN type. When this function returns anything other than S_OK, this value is **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be used to retrieve an [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) interface for the given PIN type. The **GetPinManager** method retrieves an **IMbnPinManager** interface from the [IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin) object passed in [IMbnPinEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinevents) methods.

## See also

[IMbnPin](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpin)