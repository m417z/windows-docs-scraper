# IBDA_ConditionalAccess::get_SmartCardApplications

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SmartCardApplications** method retrieves a list of the smart card applications.

## Parameters

### `pulcApplications` [in, out]

Receives a count of the number of smart card applications in the *rgApplications* array.

### `ulcApplicationsMax` [in]

The maximum number of smart card applications that the *rgApplications* buffer can hold.

### `rgApplications` [in, out]

Pointer to a buffer that receives an array of smart card applications. Each array element is a [SmartCardApplication](https://learn.microsoft.com/windows/desktop/api/bdaiface/ns-bdaiface-smartcardapplication) structure.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

**Note**The *pulcApplications* parameter is marked in the IDL file as [in, out] but is used as an [in] parameter. To preserve binary compatibility with previous versions, it has not been changed.

## See also

[IBDA_ConditionalAccess Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccess)