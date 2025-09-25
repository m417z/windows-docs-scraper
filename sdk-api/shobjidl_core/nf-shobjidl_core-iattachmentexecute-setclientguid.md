# IAttachmentExecute::SetClientGuid

## Description

Specifies and stores the GUID for the client.

## Parameters

### `guid` [in]

Type: **REFGUID**

The GUID that represents the client.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A user can choose not to display certain prompts. That information is stored in the registry on a per-client basis, indexed by *guid*.