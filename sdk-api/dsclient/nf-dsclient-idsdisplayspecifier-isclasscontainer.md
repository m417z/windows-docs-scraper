# IDsDisplaySpecifier::IsClassContainer

## Description

The **IDsDisplaySpecifier::IsClassContainer** method determines if a given object class is a container.

## Parameters

### `pszObjectClass` [in]

Pointer to a null-terminated Unicode string that contains the name of the object class to determine if it is a container. Examples of the object class name are "user" and "container".

### `pszADsPath` [in]

Pointer to a null-terminated Unicode string that contains the **ADsPath** of a class object that can be bound to in the display specifier container and whose schema data can be obtained.

### `dwFlags` [in]

Contains flags that modify the behavior of this method. This can be zero or the following flag.

#### DSICCF_IGNORETREATASLEAF

The **treatAsLeaf** attribute in the display specifier is ignored and only the schema data is used to determine if the class is a container.

## Return value

Returns **TRUE** if the specified class is a container. Otherwise it returns **FALSE**.

## Remarks

The method uses the schema data and/or the **treatAsLeaf** attribute of the display specifier to determine if an object class is a container. The object class is determined to be a container if the schema indicates that the class can contain other objects. The **treatAsLeaf** attribute of the display specifier can be used to override the schema indicator.

## See also

[Display Interfaces in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-interfaces-in-active-directory-domain-services)

[IDsDisplaySpecifier](https://learn.microsoft.com/windows/desktop/api/dsclient/nn-dsclient-idsdisplayspecifier)