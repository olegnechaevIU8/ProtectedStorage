#ifndef PROTECTED_STORAGE_H
#define PROTECTED_STORAGE_H

#include <string>

enum class storageCreateStatus {
	alreadyCreated,
	noArguments,
	fewArguments,
	errorInCreating,
	successfullyCreated
};

enum class storageDestroyStatus {
	nothingToDestroy,
	errorInDestroying,
	successfullyDestroyed
};

class ProtectedStorage {

public:
	static ProtectedStorage* getInstance();

	~ProtectedStorage();

	ProtectedStorage(const ProtectedStorage& ) = delete;

	ProtectedStorage(ProtectedStorage&& ) = delete;

	ProtectedStorage& operator=(const ProtectedStorage& ) = delete;

	ProtectedStorage& operator=(ProtectedStorage&& ) = delete;

	storageCreateStatus createStorage(char** data, int size);

	storageDestroyStatus destroyStorage();

	bool isMounted() const;

private:
	std::string mMountdir;

	bool mIsMounted;

	ProtectedStorage();

	static ProtectedStorage* pInstance;
};

#endif
