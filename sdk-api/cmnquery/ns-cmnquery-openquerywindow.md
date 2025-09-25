# OPENQUERYWINDOW structure

## Description

The **OPENQUERYWINDOW** structure is used with
the [ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow) method to
initialize the directory service query dialog box.

## Members

### `cbStruct`

Contains the size, in bytes, of the structure. This member is used for versioning and parameter validation
and must be filled in before calling
[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow).

### `dwFlags`

Contains a set of flags that define the behavior of the directory service query dialog box. This can be
zero or a combination of one or more of the values listed in the following list.

#### OQWF_DEFAULTFORM

Causes the query dialog box to select the form specified by the
**clsidDefaultForm** member on initialization.

#### OQWF_HIDEMENUS

Causes the dialog box to hide the menu bar.

#### OQWF_HIDESEARCHUI

Causes the query dialog box to be created without the standard search user interface. This includes the
**Find Now**, **Stop** and
**Clear All** pushbuttons.

#### OQWF_ISSUEONOPEN

Causes the query to be executed when the query dialog box is first displayed.

#### OQWF_LOADQUERY

Causes the query dialog box to retrieve the query from the
[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery) interface in the
**pPersistQuery** member.

#### OQWF_OKCANCEL

Causes the query dialog box to display the **OK** and
**Cancel** buttons, if applicable. The buttons actually displayed in the dialog box
will depend on the form used and other specified flags.

#### OQWF_PARAMISPROPERTYBAG

Indicates that the **ppbFormParameters** member contains an
[IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) interface.

#### OQWF_REMOVEFORMS

Causes the query dialog box to be created without the form chooser label and drop-down list represented
by the **Find:** label.

#### OQWF_REMOVESCOPES

Causes the query dialog box to be created without the scope label and drop-down list represented by the
**In:** label.

#### OQWF_SAVEQUERYONOK

Causes the query dialog box, when closed, to save the query to the
[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery) interface in the
**pPersistQuery** member.

#### OQWF_SHOWOPTIONAL

Causes the query dialog box to display optional forms in the form drop-down list. Optional forms are
forms that specify the **CQFF_ISOPTIONAL** flag in the
**dwFlags** member of the [CQFORM](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqform)
structure.

#### OQWF_SINGLESELECT

Causes the query dialog box to make the query results list single-selection.

### `clsidHandler`

Contains a **CLSID** value that specifies the query handler to be used by the
query dialog box. The value of this member also determines the type of structure pointed to by the
**pHandlerParameters** member.

#### CLSID_DsQuery

This is the standard directory service query and the only currently supported query.

### `pHandlerParameters`

Pointer to a structure that contains data for the query handler. The type of structure pointed to by this
member is defined by the **clsidHandler** member. The following list lists the possible
types of structures based on the value of the **clsidHandler** member.

#### CLSID_DsQuery

Contains a pointer to a [DSQUERYINITPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryinitparams)
structure.

### `clsidDefaultForm`

Specifies the default form to be displayed in the query dialog box. This member is ignored if
**dwFlags** does not contain **OQWF_DEFAULTFORM**. This member can
contain the **CLSID** of a custom query form or one of the system-supplied forms.

#### CLSID_DsFindAdvanced

Identifies the **Custom Search** query form.

#### CLSID_DsFindComputer

Identifies the **Computers** query form.

#### CLSID_DsFindContainer

Identifies the **Organizational Units** query form.

#### CLSID_DsFindDomainController

Identifies the **Domain Controllers** query form.

#### CLSID_DsFindFrsMembers

Identifies the **FRS Members** query form.

#### CLSID_DsFindObjects

Reserved.

#### CLSID_DsFindPeople

Identifies the **Users, Contacts, and Groups** query form.

#### CLSID_DsFindPrinter

Identifies the **Printers** query form.

#### CLSID_DsFindVolume

Identifies the **Shared Folders** query form.

#### CLSID_DsFindWriteableDomainController

Identifies the **Domain Controllers** query form and displays writable Domain
Controllers.

### `pPersistQuery`

Pointer to an [IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery) interface used
to store and retrieve query data. This data pertains to the query itself, not the results of the query. If
**dwFlags** contains **OQWF_LOADQUERY**, the query data is obtained
from this interface. If **dwFlags** contains **OQWF_SAVEQUERY**,
the query data is saved to this interface.

### `pFormParameters`

Reserved. Pointer to a structure or interface that provides parameter initialization data for the form.
The contents of this pointer is defined by the form class specified by the
**clsidDefaultForm** member.

### `ppbFormParameters`

Pointer to an [IPropertyBag](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ipropertybag) interface that
provides parameter initialization data for the form. The contents of this property bag are defined by the form
class specified by the **clsidDefaultForm** member. The following system-supplied forms
support this member.

#### CLSID_DsFindPrinter

This form obtains the following properties from the property bag.

| Property name | Description |
| --- | --- |
| printName | Contains the initial printer name. |
| printLocation | Contains the initial printer location. |
| printModel | Contains the initial model name and/or number of the printer. |

#### CLSID_DsFindComputer

Use this form to specify the computer roles. The property bag must include computerRole. Use a combination
of the following values to restrict which roles are included:

| Value | Role |
| --- | --- |
| 0x0000 | All roles |
| 0x0001 | Workstation or Server |
| 0x0002 | All Domain Controllers |
| 0x0004 | Writable Domain Controllers |
| 0x0008 | Read-only Domain Controllers |

## See also

[CQFORM](https://learn.microsoft.com/windows/desktop/api/cmnquery/ns-cmnquery-cqform)

[DSQUERYINITPARAMS](https://learn.microsoft.com/windows/desktop/api/dsquery/ns-dsquery-dsqueryinitparams)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[ICommonQuery::OpenQueryWindow](https://learn.microsoft.com/windows/desktop/api/cmnquery/nf-cmnquery-icommonquery-openquerywindow)

[IPersistQuery](https://learn.microsoft.com/windows/desktop/api/cmnquery/nn-cmnquery-ipersistquery)