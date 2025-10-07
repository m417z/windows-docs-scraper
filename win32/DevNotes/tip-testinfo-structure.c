struct TestInfo
{
    GUID testId;
    unsigned int dataSequenceId;
    unsigned int flags;
    PSTR data;
    LONGLONG startPerformanceCounter;
    unsigned int observedSleepTimeInMs;
    unsigned int properties;
};