## Syntax

```cpp
const DEVPROPERTY* WINAPI DevFindProperty(
    [in] const DEVPROPKEY *pKey,
    [in] DEVPROPSTORE Store,
    [in] PCWSTR pszLocaleName,
    [in] ULONG cProperties,
    [in] const DEVPROPERTY *pProperties);
```

## Description

Finds the [DEVPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/install/devproperty) that corresponds to a particular property within an array of **DEVPROPERTY** structures.

## Parameters

### `pKey` [in]

A [DEVPROPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropkey) value identifying the property to find.

### `Store`

The **DEVPROPSTORE** value that indicates the property store of the property to find.

### `pszLocaleName` [in,optional]

The locale name of the property to find. Typically, this will be NULL.

### `cProperties` [in]

The count of elements pointed at by *pProperties*.

### `pProperties` [in]

An array of **DEVPROPERTY** structures to search for the specified property in.

## Return value

A pointer to the **DEVPROPERTY** structure that matches the specified search criteria or NULL if no matching property was found.

## Remarks

## See also