# CQFORM structure

## Description

The **CQFORM** structure is used to define a query form added to the query dialog box with the [CQAddFormsProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddformsproc) callback function.

## Members

### `cbStruct`

Contains the size, in bytes, of the structure.

### `dwFlags`

Contains a set of flags that modify the behavior of the query form. This can be zero or a combination of one or more of the following values.

#### CQFF_ISOPTIONAL

Specifies that this query form is optional and is only displayed if optional forms are requested.

#### CQFF_NOGLOBALPAGES

Specifies that this form should not have the global pages added to it.

### `clsid`

Contains the class identifier used to identify the query form.

### `hIcon`

Contains the handle of the icon to be displayed with the query form.

### `pszTitle`

Pointer to a null-terminated Unicode string that contains the title of the query form.

## See also

[CQAddFormsProc](https://learn.microsoft.com/windows/desktop/api/cmnquery/nc-cmnquery-lpcqaddformsproc)

[Display Structures in Active
Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[IQueryForm::AddForms](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-iqueryform-addforms)