# IGroupPolicyObject::Save

## Description

The
**Save** method saves the specified registry policy settings to disk and updates the revision number of the GPO.

## Parameters

### `bMachine` [in]

Specifies the registry policy settings to be saved. If this parameter is **TRUE**, the computer policy settings are saved. Otherwise, the user policy settings are saved.

### `bAdd` [in]

Specifies whether this is an add or delete operation. If this parameter is **FALSE**, the last policy setting for the specified extension *pGuidExtension* is removed. In all other cases, this parameter is **TRUE**.

### `pGuidExtension` [in]

Specifies the GUID or unique name of the snap-in extension that will process policy. If the GPO is to be processed by the snap-in that processes .pol files, you must specify the REGISTRY_EXTENSION_GUID value.

### `pGuid` [in]

Specifies the GUID that identifies the MMC snap-in used to edit this policy. The snap-in can be a Microsoft snap-in or a third-party snap-in.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the method returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

**Note** A policy refresh will be automatically triggered when the user or computer portion of the local Group Policy object is enabled or disabled using the **Save** method.

## See also

[Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-delete)

[Group Policy
Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-interfaces)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[IGroupPolicyObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nn-gpedit-igrouppolicyobject)

[New](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpedit/nf-gpedit-igrouppolicyobject-new)