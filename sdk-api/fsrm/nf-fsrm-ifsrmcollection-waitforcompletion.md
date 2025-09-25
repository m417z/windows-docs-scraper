# IFsrmCollection::WaitForCompletion

## Description

Limits the time that an asynchronous collection can take to collect the objects.

**Note** Asynchronous collections are not supported by FSRM, therefore this method always sets the *completed* parameter to **VARIANT_TRUE**.

## Parameters

### `waitSeconds` [in]

The number of seconds to wait for the collection to finish collecting objects. To wait indefinitely, set this parameter to –1.

### `completed` [out]

Is **VARIANT_TRUE** if the collection finished collecting objects in the time specified; otherwise, **VARIANT_FALSE**.

## Return value

This method is not supported and always returns **S_OK**.

## See also

[IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection)