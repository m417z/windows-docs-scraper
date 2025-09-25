# ADsPropCheckIfWritable function

## Description

The **ADsPropCheckIfWritable** function determines if an attribute can be written.

## Parameters

### `pwzAttr` [in]

Pointer to a NULL-terminated **WCHAR** buffer that contains the name of the attribute.

### `pWritableAttrs` [in]

Pointer to the array of [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structures returned by [ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo).

## Return value

Returns nonzero if the attribute is found in the writable-attribute list or zero otherwise. Also returns zero if *pWritableAttrs* is **NULL**.

## Remarks

During initialization, a property sheet extension should determine if the attributes it can change can be written by using **ADsPropCheckIfWritable**. If an attribute cannot be written, it should be displayed as read-only and the ability to change the attribute value should be removed.

It is possible for a user to be granted write permission, but not read permission for an attribute. In this case, the attribute read operation fails and it is possible that the attribute could be overwritten. Consequently, it is not recommended to grant a user write permission, but revoke read permission on an attribute.

Do not use this function to verify the write permission for attributes in a multi-select property sheet. It is likely that each directory object will have a different set of writable attribute permissions. The property sheet extension should rely on the server returning an error when attempting to write to a specific object in a selected group to determine if write permissions for that object are denied.

## See also

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[ADsPropGetInitInfo](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropgetinitinfo)