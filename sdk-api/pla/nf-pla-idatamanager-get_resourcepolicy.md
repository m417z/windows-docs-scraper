# IDataManager::get_ResourcePolicy

## Description

Retrieves or sets the action to take when one of the disk resource limits is exceeded.

This property is read/write.

## Parameters

## Remarks

The folders are deleted based on the resource policy until the disk resource condition is satisfied. For example, if the maximum size is 7 MB and the current size is 10 MB, PLA will delete folders until the current size is 7 MB or less. If the first folder to be deleted is 3 MB, PLA will delete that folder and then stop deleting folders because the current size will be equal to the maximum size. If the first folder to be deleted is 9 MB, PLA will delete that folder and then stop deleting folders because the current size will be 1 MB, which will also satisfy the condition.

## See also

[IDataManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatamanager)

[IDataManager::FolderActions](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatamanager-get_folderactions)