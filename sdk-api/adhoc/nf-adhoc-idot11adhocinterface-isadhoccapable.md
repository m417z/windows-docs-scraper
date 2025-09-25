# IDot11AdHocInterface::IsAdHocCapable

## Description

Specifies whether a NIC supports the creation or use of an ad hoc network.

## Parameters

### `pfAdHocCapable` [in, out]

A pointer to a boolean that specifies the NIC's ad hoc network capabilities. The boolean value is set to **TRUE** if the NIC supports the creation and use of ad hoc networks and **FALSE** otherwise.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_OUTOFMEMORY** | The method could not allocate the memory required to perform this operation. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## Remarks

*pfAdHocCapable* can be set to **FALSE** for many reasons, including the following:

* Group policy prohibits the use of ad hoc networks on this interface
* The machine is configured to only connect to infrastructure networks, or the machine configuration disallows wireless connections
* The NIC does not support ad hoc networks

## See also

[IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface)