# IRpcOptions::Query

## Description

Retrieves the value of an RPC binding option property.

## Parameters

### `pPrx` [in]

A pointer to the proxy whose property is being queried.

### `dwProperty` [in]

An identifier of the property to be queried, which must be COMBND_RPCTIMEOUT or COMBND_SERVER_LOCALITY (this flag is available starting with Windows Server 2003.)

### `pdwValue` [out]

A pointer to the property value.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

While the COMBND_RPCTIMEOUT property can also be set using the [Set](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irpcoptions-set) method, the COMBND_SERVER_LOCALITY property can only be queried.

See [IRpcOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcoptions) for a table of the possible values of the COMBND_RPCTIMEOUT property.

The possible values of the COMBND_SERVER_LOCALITY property, which describes the degree of remoteness of the RPC connection, are enumerated in the following table.

| Value | Description |
| --- | --- |
| SERVER_LOCALITY_PROCESS_LOCAL | The counterpart is in the same process as the client. |
| SERVER_LOCALITY_MACHINE_LOCAL | The counterpart is on the same computer as the client but in a different process. |
| SERVER_LOCALITY_REMOTE | The counterpart is on a remote computer. |

## See also

[IRpcOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcoptions)