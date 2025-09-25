# BG_JOB_TYPE enumeration

## Description

Defines constants that specify the type of transfer job, such as download.

## Constants

### `BG_JOB_TYPE_DOWNLOAD:0`

Specifies that the job downloads files to the client.

### `BG_JOB_TYPE_UPLOAD`

Specifies that the job uploads a file to the server.

**BITS 1.2 and earlier:** not supported.

### `BG_JOB_TYPE_UPLOAD_REPLY`

Specifies that the job uploads a file to the server, and receives a reply file from the server application.

**BITS 1.2 and earlier:** not supported.

## See also

* [IBackgroundCopyJob::GetType method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-gettype)
* [IBackgroundCopyManager::CreateJob method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob)