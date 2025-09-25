# IContentPrefetcherTaskTrigger::TriggerContentPrefetcherTask

## Description

Triggers a content prefetch background task for the specified app package.

## Parameters

### `packageFullName` [in]

The package ID.

## Return value

Returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The provided package ID is not an installed package that has registered for the content prefetch background task, or the package ID is empty or null. |
| **E_ACCESSDENIED** | The method call was not made at the required Medium Integrity Level (Medium IL). |

## See also

[IContentPrefetcherTaskTrigger](https://learn.microsoft.com/windows/desktop/api/icontentprefetchertasktrigger/nn-icontentprefetchertasktrigger-icontentprefetchertasktrigger)