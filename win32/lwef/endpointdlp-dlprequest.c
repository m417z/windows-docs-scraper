struct DlpRequest
{
    DlpRequestId id;
    uint32_t size;
    //! The data associated with the request being performed
    union
    {
        AuthGroupOverrideRequest* authGroupOverrideRequest;
        GetFileCloudApplicationPolicyRequest* getFileCloudApplicationPolicyRequest;
        GetFileApplicationAccessRequest* getFileApplicationAccessRequest;
        GetNotificationSettingRequest* getNotificationSettingRequest;
        SendOperationEnforcementEventRequest* sendOperationEnforcementEventRequest;
        SendFileAccessEventRequest* sendFileAccessEventRequest;
    };
};