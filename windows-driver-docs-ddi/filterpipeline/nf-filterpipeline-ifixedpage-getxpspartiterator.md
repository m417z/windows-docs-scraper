# IFixedPage::GetXpsPartIterator

## Description

The **GetXpsPartIterator** method gets an iterator to enumerate all of the parts that are associated with the page.

## Parameters

### `pXpsPartIt` [out]

An iterator that you can use to enumerate all of the parts that are associated with the page.

## Return value

**GetXpsPartIterator** returns an **HRESULT** value.

## Remarks

Filters should not add or delete parts while using the iterator that the **GetXpsPartIterator** method retrieves.