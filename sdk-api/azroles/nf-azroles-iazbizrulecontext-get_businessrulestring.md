# IAzBizRuleContext::get_BusinessRuleString

## Description

The **BusinessRuleString** property sets or retrieves an application-specific string for the Business Rule (BizRule).

This property is read/write.

## Parameters

## Remarks

This property is returned to the application that called the [IAzClientContext::AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. One possible use of this property is to explain the reason that the BizRule denied access to the user.

The maximum length of this property is 65,536 characters.