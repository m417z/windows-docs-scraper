# DSQUERYINITPARAMS structure

## Description

The **DSQUERYINITPARAMS** structure describes the data used to initialize a browse dialog box in the directory service query.

## Members

### `cbStruct`

Contains the size, in bytes, of this structure.

### `dwFlags`

Contains a set of flags that define the query behavior. This can be zero or a combination of one or more of the following values.

#### DSQPF_ENABLEADMINFEATURES

Uses features supported by the directory service administration tools, such as Admin Display Specifier for context menus and property pages.

#### DSQPF_ENABLEADVANCEDFEATURES

Specifies advanced features in the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) instance passed to context menus and property pages.

#### DSQPF_HASCREDENTIALS

The **pUserName**, **pPassword** and **pServer** members of this structure can specify server and credential data.

#### DSQPF_NOCHOOSECOLUMNS

Disables the **Choose Columns** item in the query dialog box **View** menu.

#### DSQPF_NOSAVE

Removes the **Save Search** item from the query dialog box **File** menu.

#### DSQPF_SAVELOCATION

The **pDefaultSaveLocation** member contains the default file system path where searches will be saved.

#### DSQPF_SHOWHIDDENOBJECTS

Causes the query dialog box to display hidden objects in the query results list.

### `pDefaultScope`

Pointer to a null-terminated Unicode string that contains the ADsPath of the default scope for the search. Set this member to **NULL** if no default search scope is specified.

### `pDefaultSaveLocation`

Pointer to a null-terminated Unicode string that contains the default file system path where searches will be saved. This member is ignored if the **dwFlags** member does not contain **DSQPF_SAVELOCATION**.

### `pUserName`

Pointer to a null-terminated Unicode string that contains the user name in the valid domain notation, for example, "fabrikam\jeffsmith".

### `pPassword`

Pointer to a null-terminated Unicode string that contains the password of the user specified by the **pUserName** member.

### `pServer`

Pointer to a null-terminated Unicode string that contains the name of the server from which the list of trusted domains is read. The list is used to populate the **In:** drop-down list in the dialog box.

## Remarks

This structure is specific to the **CLSID_DsQuery** query handler. This structure is used for the **pHandlerParameters** member of the [OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow) structure when **CLSID_DsQuery** is set for the **clsidHandler** member of the
**OPENQUERYWINDOW** structure. For more information, and a code example for using this, and other related APIs, see
[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow).

## See also

[Active
Directory Display Structures](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[OPENQUERYWINDOW](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-openquerywindow)