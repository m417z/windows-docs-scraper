# MoveOptions enumeration

Defines constants that specify options for the [Move](https://learn.microsoft.com/windows/win32/appxpkg/appxdatasource/nf-appxdatasource-iappxstreamingdatasource4-move) method.

## Constants

|   |
| -- |
| `BeginMove`<br> Begin the move operation from the source to the target volume. |
| `EndMove`<br> End the move operation from the source to the target volume (for example, delete source files). |
| `RollbackMove`<br> Abort the move operation, and restore files to the source volume. |
| `MoveOptionsInvalid`<br> Specfies invalid move options. |

## Requirements

|   |   |
| ---- |:---- |
| **Header** | appxdatasource.h |