# IOperationsProgressDialog::UpdateProgress

## Description

Updates the current progress dialog, as specified.

## Parameters

### `ullPointsCurrent` [in]

Type: **ULONGLONG**

Current points, used for showing progress in points.

### `ullPointsTotal` [in]

Type: **ULONGLONG**

Total points, used for showing progress in points.

### `ullSizeCurrent` [in]

Type: **ULONGLONG**

Current size in bytes, used for showing progress in bytes.

### `ullSizeTotal` [in]

Type: **ULONGLONG**

Total size in bytes, used for showing progress in bytes.

### `ullItemsCurrent` [in]

Type: **ULONGLONG**

Current items, used for showing progress in items.

### `ullItemsTotal` [in]

Type: **ULONGLONG**

Specifies total items, used for showing progress in items.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.