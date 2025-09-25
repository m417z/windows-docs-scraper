# JOBOBJECT_END_OF_JOB_TIME_INFORMATION structure

## Description

Specifies the action the system will perform when an end-of-job time limit is exceeded.

## Members

### `EndOfJobTimeAction`

The action that the system will perform when the end-of-job time limit has been exceeded. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_TERMINATE_AT_END_OF_JOB**<br><br>0 | Terminates all processes and sets the exit status to ERROR_NOT_ENOUGH_QUOTA. The processes cannot prevent or delay their own termination. The job object is set to the signaled state and remains signaled until this limit is reset. No additional processes can be assigned to the job until the limit is reset. <br><br>This is the default termination action. |
| **JOB_OBJECT_POST_AT_END_OF_JOB**<br><br>1 | Posts a completion packet to the completion port using the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function. After the completion packet is posted, the system clears the end-of-job time limit, and processes in the job can continue their execution. <br><br>If no completion port is associated with the job when the time limit has been exceeded, the action taken is the same as for JOB_OBJECT_TERMINATE_AT_END_OF_JOB. |

## Remarks

The end-of-job time limit is specified in the **PerJobUserTimeLimit** member of the
[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure.

To associate a completion port with a job, use the
[JOBOBJECT_ASSOCIATE_COMPLETION_PORT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_associate_completion_port) structure.

## See also

[JOBOBJECT_ASSOCIATE_COMPLETION_PORT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_associate_completion_port)

[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information)

[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)