# SHAssocEnumHandlers function

## Description

Returns an enumeration object for a specified set of file name extension handlers.

## Parameters

### `pszExtra` [in]

Type: **PCWSTR**

A pointer to a null-terminated buffer that contains a single file type extension, for instance ".jpg". Only handlers associated with the given extension are enumerated. This parameter may not be **NULL**.

### `afFilter` [in]

Type: **ASSOC_FILTER**

Specifies the enumeration handler filter applied to the full list of handlers that results from the value given in *pszExtra*. One of the following values.

| Value | Description |
|-------|-------------|
| ASSOC_FILTER_NONE | Return all handlers. |
| ASSOC_FILTER_RECOMMENDED | Return only recommended handlers. A handler sets its recommended status in the registry when it is installed. An initial status of non-recommended can later be promoted to recommended as a result of user action. |

### `ppEnumHandler` [out]

Type: **[IEnumAssocHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumassochandlers)****

When this method returns, contains the address of a pointer to an [IEnumAssocHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumassochandlers) object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.