# JOBOBJECT_ASSOCIATE_COMPLETION_PORT structure

## Description

Contains information used to associate a completion port with a job. You can associate one completion port with a job.

## Members

### `CompletionKey`

The value to use in the *dwCompletionKey* parameter of
[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) when messages are sent on behalf of the job.

### `CompletionPort`

The completion port to use in the *CompletionPort* parameter of the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function when messages are sent on behalf of the job.

**Windows 8 and newer, Windows Server 2012 and newer:** Specify **NULL** to remove the association between the current completion port and the job.

## Remarks

The system sends messages to the I/O completion port associated with a job when certain events occur. If the job is nested, the message is sent to every I/O completion port associated with any job in the parent job chain of the job that triggered the message. All messages are sent directly from the job as if the job had called the
[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function.

Note that, except for limits set with the **JobObjectNotificationLimitInformation** information class, messages are intended only as notifications and their delivery to the completion port is not guaranteed. The failure of a message to arrive at the completion port does not necessarily mean that the event did not occur. Notifications for limits set with **JobObjectNotificationLimitInformation** are guaranteed to arrive at the completion port.

A thread must monitor the completion port using the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function to pick up the messages. The thread receives information in the **GetQueuedCompletionStatus** parameters shown in the following table.

| Parameter | Information Received |
| --- | --- |
| *lpCompletionKey* | The value specified in *CompletionKey* during the completion-port association. If a completion port is associated with multiple jobs, *CompletionKey* should help the caller determine which completion port is sending a message. |
| *lpOverlapped* | Message-specific value. For more information, see the following table of message identifiers. |
| *LpNumberOfBytes* | The message identifier that indicates which job-related event occurred. For more information, see the following table of message identifiers. |

The following messages can be sent to the completion port. Note that for messages that return a process identifier, you cannot guarantee that this process is still active or that the identifier has not been recycled (assigned to a new process after termination) unless you maintain an open handle to the process.

| Message Identifier | Description |
| --- | --- |
| JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS | Indicates that a process associated with the job exited with an exit code that indicates an abnormal exit (see the list following this table). <br><br>The value of *lpOverlapped* is the identifier of the exiting process. |
| JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT | Indicates that the active process limit has been exceeded. <br><br>The value of *lpOverlapped* is NULL. |
| JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO | Indicates that the active process count has been decremented to 0. For example, if the job currently has two active processes, the system sends this message after they both terminate. <br><br>The value of *lpOverlapped* is NULL. |
| JOB_OBJECT_MSG_END_OF_JOB_TIME | Indicates that the JOB_OBJECT_POST_AT_END_OF_JOB option is in effect and the end-of-job time limit has been reached. Upon posting this message, the time limit is canceled and the job's processes can continue to run. <br><br>The value of *lpOverlapped* is NULL. |
| JOB_OBJECT_MSG_END_OF_PROCESS_TIME | Indicates that a process has exceeded a per-process time limit. The system sends this message after the process termination has been requested. <br><br>The value of *lpOverlapped* is the identifier of the process that exceeded its limit. |
| JOB_OBJECT_MSG_EXIT_PROCESS | Indicates that a process associated with the job has exited. <br><br>The value of *lpOverlapped* is the identifier of the exiting process. |
| JOB_OBJECT_MSG_JOB_MEMORY_LIMIT | Indicates that a process associated with the job caused the job to exceed the job-wide memory limit (if one is in effect). <br><br>The value of *lpOverlapped* specifies the identifier of the process that has attempted to exceed the limit. The system does not send this message if the process has not yet reported its process identifier. |
| JOB_OBJECT_MSG_NEW_PROCESS | Indicates that a process has been added to the job. Processes added to a job at the time a completion port is associated are also reported. <br><br>The value of *lpOverlapped* is the identifier of the process added to the job. |
| JOB_OBJECT_MSG_NOTIFICATION_LIMIT | Indicates that a process associated with a job that has registered for resource limit notifications has exceeded one or more limits. Use the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with JobObjectLimitViolationInformation to determine which limit was exceeded. <br><br>The value of *lpOverlapped* is the identifier of the process that has exceeded its limit. The system does not send this message if the process has not yet reported its process identifier. |
| JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT | Indicates that a process associated with the job has exceeded its memory limit (if one is in effect). <br><br>The value of *lpOverlapped* is the identifier of the process that has exceeded its limit. The system does not send this message if the process has not yet reported its process identifier. |

The following exit codes indicate an abnormal exit:

* STATUS_GUARD_PAGE_VIOLATION
* STATUS_DATATYPE_MISALIGNMENT
* STATUS_BREAKPOINT
* STATUS_SINGLE_STEP
* STATUS_ACCESS_VIOLATION
* STATUS_IN_PAGE_ERROR
* STATUS_ILLEGAL_INSTRUCTION
* STATUS_NONCONTINUABLE_EXCEPTION
* STATUS_INVALID_DISPOSITION
* STATUS_ARRAY_BOUNDS_EXCEEDED
* STATUS_FLOAT_DENORMAL_OPERAND
* STATUS_FLOAT_DIVIDE_BY_ZERO
* STATUS_FLOAT_INEXACT_RESULT
* STATUS_FLOAT_INVALID_OPERATION
* STATUS_FLOAT_OVERFLOW
* STATUS_FLOAT_STACK_CHECK
* STATUS_FLOAT_UNDERFLOW
* STATUS_INTEGER_DIVIDE_BY_ZERO
* STATUS_INTEGER_OVERFLOW
* STATUS_PRIVILEGED_INSTRUCTION
* STATUS_STACK_OVERFLOW
* STATUS_CONTROL_C_EXIT
* STATUS_FLOAT_MULTIPLE_FAULTS
* STATUS_FLOAT_MULTIPLE_TRAPS
* STATUS_REG_NAT_CONSUMPTION

You must be cautious when using the JOB_OBJECT_MSG_NEW_PROCESS and JOB_OBJECT_MSG_EXIT_PROCESS messages, as race conditions may occur. For instance, if processes are actively starting and exiting within a job, and you are in the process of assigning a completion port to the job, you may miss messages for processes whose states change during the association of the completion port. For this reason, it is best to associate a completion port with a job when the job is inactive.

## See also

[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)