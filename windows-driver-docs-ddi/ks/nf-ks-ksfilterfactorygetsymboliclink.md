# KsFilterFactoryGetSymbolicLink function

## Description

The **KsFilterFactoryGetSymbolicLink** function returns the symbolic link associated with a given filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to a [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) structure for which to acquire the symbolic link.

## Return value

**KsFilterFactoryGetSymbolicLink** returns a pointer to a Unicode string containing the [symbolic link](https://learn.microsoft.com/windows-hardware/drivers/) for the filter factory if the call is successful, and **NULL** if unsuccessful. **NULL** indicates that no device interfaces have been registered for *FilterFactory*.

## Remarks

If *FilterFactory* has no registered device interfaces, **KsFilterFactoryGetSymbolicLink** returns **NULL**.