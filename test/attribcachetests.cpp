#include <uuid/uuid.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "blobfuse.h"

class MockBlobClient : public sync_blob_client {
    MOCK_METHOD5(download_blob_to_file, void(const std::string &container, const std::string &blob, const std::string &destPath, time_t &returned_last_modified, size_t parallel));
    MOCK_METHOD2(get_blob_property, blob_property(const std::string &container, const std::string &blob));
    MOCK_METHOD2(blob_exists, bool(const std::string &container, const std::string &blob));
    MOCK_METHOD2(delete_blob, void(const std::string &container, const std::string &blob));
    MOCK_METHOD4(start_copy, void(const std::string &sourceContainer, const std::string &sourceBlob, const std::string &destContainer, const std::string &destBlob));
};

class AttribCacheTest : public ::testing::Test {
public:
    static std::shared_ptr<blob_client_wrapper> test_blob_client_wrapper;

    // This runs once, before any tests in "AttribCacheTest"
    static void SetUpTestCase() {
        ASSERT_EQ(0, 0) << "Read config failed.";
    }

    std::string container_name;


    // This runs before each test.
    virtual void SetUp()
    {
        uuid_t container_uuid;
        uuid_generate( (unsigned char *)&container_uuid );

        char container_name_uuid[37];
        uuid_unparse_lower(container_uuid, container_name_uuid);

        std::string container_name_prefix = "container";
        container_name = container_name_prefix + container_name_uuid;
        container_name.erase(std::remove(container_name.begin(), container_name.end(), '-'), container_name.end());
        errno = 0;
    }

    virtual void TearDown()
    {
    }
};

TEST_F(AttribCacheTest, GetBlobProperties)
{
    ASSERT_EQ(1, 0) << "sample";

}