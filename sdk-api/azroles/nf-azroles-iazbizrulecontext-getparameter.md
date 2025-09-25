# IAzBizRuleContext::GetParameter

## Description

The **GetParameter** method gets the specified value from the *varParameterValues* parameter of the [IAzClientContext::AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method.

## Parameters

### `bstrParameterName` [in]

Name of the value to return. The name must match the name in one of the elements in the array passed into the *varParameterNames* parameter of the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method.

**Important** Users of VBScript must be aware that the comparison between this parameter and the names in the *varParameterNames* parameter is case sensitive.

### `pvarParameterValue` [out]

Parameter value from the *varParameterValues* parameter of the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method that corresponds to the name specified by the *bstrParameterName* parameter, if found; otherwise, **NULL**.

## Return value

 If the method succeeds, the method returns S_OK.

Any other **HRESULT** value indicates that the operation failed.