# DSCOLUMN structure

## Description

The **DSCOLUMN** structure represents a column in the directory services query dialog box. An array of this structure is contained in the [DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryparams) structure.

## Members

### `dwFlags`

Reserved.

### `fmt`

Contains one of the list view column formatting values that indicates how the column is displayed. The possible values are defined for the **fmt** member of the [LVCOLUMN](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna) structure.

### `cx`

Contains the width, in pixels, of the column.

### `idsName`

Contains the string table identifier for the column header string. To retrieve this string, call [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa) with the **hInstance** member of the [DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryparams) structure and this member for the string identifier.

### `offsetProperty`

Indicates the name of the attribute displayed in the column. This can be one of the following values.

#### DSCOLUMNPROP_ADSPATH

The column displays the value of the ADsPath of the object.

#### DSCOLUMNPROP_OBJECTCLASS

The column displays the value of the **objectClass** of the object.

If this member does not contain one of these values, this member contains the offset, in bytes, from the address of the [DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryparams) structure to a null-terminated Unicode string that contains the name of the attribute value displayed in this column.

### `dwReserved`

Reserved.

## See also

[DSQUERYPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryparams)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow)

[LVCOLUMN](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvcolumna)

[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringa)