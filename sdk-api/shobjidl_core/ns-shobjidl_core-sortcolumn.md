# SORTCOLUMN structure

## Description

Stores information about how to sort a column that is displayed in the folder view.

## Members

### `propkey`

Type: **[PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey)**

The ID of the column by which the user will sort. A [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure. For example, for the "Name" column, the property key is PKEY_ItemNameDisplay.

### `direction`

Type: **SORTDIRECTION**

The direction in which the items are sorted. One of the following values.

#### SORT_DESCENDING

The items are sorted in ascending order. Whether the sort is alphabetical, numerical, and so on, is determined by the data type of the column indicated in **propkey**.

#### SORT_ASCENDING

The items are sorted in descending order. Whether the sort is alphabetical, numerical, and so on, is determined by the data type of the column indicated in **propkey**.

## Remarks

Each column displayed in the folder view (for example, "details" view mode), is associated with a property that has a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) ID. When you want to sort the view by a particular property, you specify the property key for that property.