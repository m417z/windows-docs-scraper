# IWSMan::CreateConnectionOptions

## Description

Creates an [IWSManConnectionOptions](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanconnectionoptions) object that specifies the user name and password used when creating a session.

## Parameters

### `connectionOptions` [out]

A pointer to a new [IWSManConnectionOptions](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanconnectionoptions) object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSMan](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsman)

[WSMan.CreateConnectionOptions](https://learn.microsoft.com/windows/desktop/WinRM/wsman-createconnectionoptions)