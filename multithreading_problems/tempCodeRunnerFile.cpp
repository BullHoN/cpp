    auto startRec = std::chrono::high_resolution_clock::now();
    mergeSort(0,n-1,arr);

    auto endRec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRec = endRec - startRec;
    std::cout << "Time taken by function: " << durationRec.count() << " seconds" << std::endl;