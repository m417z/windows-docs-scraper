# RunOptions enumeration

Defines constants that specify options for the [Run](https://learn.microsoft.com/windows/win32/appxpkg/appxdatasource/nf-appxdatasource-iappxstreamingdatasource4-run) method.

## Constants

|   |
| -- |
| `StageRequired`<br> Start the stage request for the required launch chunk. |
| `StageDeferred`<br> Start the stage request for the post-launch chunk. |
| `StageRevalidate`<br> Start the stage request and re-validate all bits currently on disk. |
| `RunOptionsInvalid`<br> Specfies invalid run options. |

## Requirements

|   |   |
| ---- |:---- |
| **Header** | appxdatasource.h |