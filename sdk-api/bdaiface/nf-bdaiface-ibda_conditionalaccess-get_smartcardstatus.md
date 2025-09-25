# IBDA_ConditionalAccess::get_SmartCardStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SmartCardStatus** method retrieves the status of the smart card.

## Parameters

### `pCardStatus` [out]

Pointer to a variable of type [SmartCardStatusType](https://learn.microsoft.com/windows/desktop/api/bdaiface/ne-bdaiface-smartcardstatustype) that receives the card status type.

### `pCardAssociation` [out]

Pointer to a variable of type [SmartCardAssociationType](https://learn.microsoft.com/windows/desktop/api/bdaiface/ne-bdaiface-smartcardassociationtype) that receives the card association type.

### `pbstrCardError` [out]

Receives a string containing the card error. When the string is no longer required, call the **SysFreeString** function to free it.

### `pfOOBLocked`

Receives a value indicating if the operation is blocked.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

All three parameters must be non-NULL or the method fails and returns **E_POINTER**.

## See also

[IBDA_ConditionalAccess Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccess)