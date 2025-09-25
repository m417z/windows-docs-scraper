# SMMCDataObjects structure

## Description

The
**SMMCDataObjects** structure defines the format of the data for the
[CCF_MULTI_SELECT_SNAPINS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-multi-select-snapins) clipboard format. The structure contains the array of pointers to the multiselection data object of each snap-in represented in the set of selected items in the result pane.

## Members

### `count`

The number of snap-ins whose items are selected in the result pane.

### `lpDataObject`

Array of pointers to the multiselection data objects for each snap-in selected in the result pane.

## Remarks

Each data object consists of the node types associated with a given snap-in. Data objects are passed using
[GlobalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globalalloc).

The multiselection data objects hold a list that contains each node type represented in the set of selected items for that particular snap-in in the result pane. The list of node types from a particular multiselection data object can be retrieved as an array of node type GUIDs by calling **IDataObject::GetData** on that data object with the
[CCF_OBJECT_TYPES_IN_MULTI_SELECT](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-object-types-in-multi-select) clipboard format.

Each multiselection data object also holds a list that contains the selected items owned by a particular snap-in. Each snap-in is responsible for defining the format and method of retrieval of the list of its selected items.

## See also

[CCF_MULTI_SELECT_SNAPINS](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-multi-select-snapins)

[Multiselection](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/multiselection)

[SMMCObjectTypes](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-smmcobjecttypes)