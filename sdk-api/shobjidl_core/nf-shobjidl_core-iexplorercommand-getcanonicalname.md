# IExplorerCommand::GetCanonicalName

## Description

Gets the GUID of a Windows Explorer command.

## Parameters

### `pguidCommandName` [out]

Type: **GUID***

A pointer to a value that, when this method returns successfully, receives the command's GUID, under which it is declared in the registry.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is somewhat misnamed, given that it retrieves a GUID. To retrieve the command's canonical name, you must take the additional step to pull it from the command's subkey. The GUID is the name of the subkey. where that information is stored.