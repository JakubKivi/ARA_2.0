sf::SoundBuffer buffer;
sf::Sound sound;
sf::Music music;

void loadSounds(){
    if (!music.openFromFile("audio/music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(0);

    music.play();

    music.setLoop(true);

    if (!buffer.loadFromFile("audio/sound.wav"))
        ms_error(22, "nie zaladowano dzwieku");

    sound.setBuffer(buffer);
    sound.setVolume(150.f);
}
