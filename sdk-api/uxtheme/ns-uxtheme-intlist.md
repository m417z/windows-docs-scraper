# INTLIST structure

## Description

Contains an array or list of **int** data items from a visual style.

## Members

### `iValueCount`

Type: **int**

Number of values in the list.

### `iValues`

Type: **int[MAX_INTLIST_COUNT]**

List of integers. The constant MAX_INTLIST_COUNT, by definition, is equal to 402 under Windows Vista, but only 10 under earlier versions of Windows.

## Remarks

The lists are returned by [GetThemeIntList](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemeintlist).