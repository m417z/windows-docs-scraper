# DSQUERYPARAMS structure

## Description

The **DSQUERYPARAMS** structure contains query data used by the directory service query when searching the directory service. This structure is provided by the [CFSTR_DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsqueryparams) clipboard format by the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) provided by the [ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow) method. The caller of **ICommonQuery::OpenQueryWindow** can use this to retrieve the filter, column data used by the result view when issuing a query against the server.

## Members

### `cbStruct`

Contains the size, in bytes, of the **DSQUERYPARAMS** structure. This member is used for versioning of the structure.

### `dwFlags`

Reserved.

### `hInstance`

Contains an instance handle used for extracting resources.

### `offsetQuery`

Contains the offset, in bytes, from the address of this structure to a null-terminated Unicode string that contains the LDAP filter.

### `iColumns`

Contains the number of elements in the **aColumns** array.

### `dwReserved`

Reserved.

### `aColumns`

Contains an array of [DSCOLUMN](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dscolumn) structures that contain the results of the query. The **iColumns** member specifies the number of elements in this array.

## See also

[CFSTR_DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/AD/cfstr-dsqueryparams)

[DSCOLUMN](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dscolumn)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow)