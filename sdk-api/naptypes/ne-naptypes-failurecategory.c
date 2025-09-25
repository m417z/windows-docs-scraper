typedef enum tagFailureCategory {
  failureCategoryNone = 0,
  failureCategoryOther = 1,
  failureCategoryClientComponent = 2,
  failureCategoryClientCommunication = 3,
  failureCategoryServerComponent = 4,
  failureCategoryServerCommunication = 5
} FailureCategory;