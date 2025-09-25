# IContentPrefetcherTaskTrigger::IsRegisteredForContentPrefetch

## Description

Indicates if an app package has registered for the content prefetch background task.

## Parameters

### `packageFullName` [in]

The package ID.

### `isRegistered` [out]

True if the app package has registered for the content prefetch background task; otherwise, false.

## Return value

Returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The method call was not made at the required Medium Integrity Level (Medium IL). |

## See also

[IContentPrefetcherTaskTrigger](https://learn.microsoft.com/windows/desktop/api/icontentprefetchertasktrigger/nn-icontentprefetchertasktrigger-icontentprefetchertasktrigger)