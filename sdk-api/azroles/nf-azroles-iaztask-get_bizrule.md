# IAzTask::get_BizRule

## Description

The **BizRule** property sets or retrieves the text of the script that implements the business rule (BizRule).

This property is read/write.

## Parameters

## Remarks

The maximum length of this property is 65,536 characters.

**Important** The [BizRuleLanguage](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrulelanguage) property must be set before this property is set.

An [IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask) object that is a child object of a delegated [IAzScope](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazscope) object cannot have an associated BizRule.

## See also

[BizRuleImportedPath](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizruleimportedpath)

[BizRuleLanguage](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iaztask-get_bizrulelanguage)

[IAzTask](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iaztask)