int main()
{
    SongData* playlist = nullptr;
    playlist = AddSong(playlist, "Under Heroine", "TUYU", "Under Mentality", "02:49");
    playlist = AddSong(playlist, "If There Was An Endpoint", "TUYU", "I'll put you in misery", "02:58");
    playlist = AddSong(playlist, "Jurus Rahasia Teleport", "JKT48", "Pajama Drive", "03:41");
    playlist = AddSong(playlist, "Ponytail dan Shu-Shu", "JKT48", "Ponytail dan Shu-Shu", "04:28");

    cout << endl;
    ShowSongs(playlist);

    cout << endl;
    cout << "Hapus Lagu: If There Was An Endpoint" << endl;
    cout << endl;
    DeleteSong(playlist, "If There Was An Endpoint");
    ShowSongs(playlist);

    Student* bestStudents = nullptr;
    bestStudents = AddToFront(bestStudents, "105224001", "Nell", "CS", 4.0);
    bestStudents = AddToFront(bestStudents, "105124010", "James", "CH", 3.8);
    bestStudents = AddToFront(bestStudents, "101124100", "John", "GP", 3.8);

    cout << "========================================" << endl;

    DeleteStudent(bestStudents, "105124010");
    bestStudents = AddToLast(bestStudents, "105222016", "Putra", "CS", 4.0);
    bestStudents = AddToLast(bestStudents, "105222027", "Naima", "CS", 3.0);
    bestStudents = AddBefore(bestStudents, "105222016", "105222022", "Han-Han", "CS", 1.0);

    cout << "Daftar Mahasiswa Terbaik (Forward):" << endl;
    ShowForward(bestStudents);

    cout << "========================================" << endl;

    cout << "Daftar Mahasiswa Terbaik (Backward):" << endl;
    ShowBackward(bestStudents);

    return 0;
}