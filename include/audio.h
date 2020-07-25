sf::Music music;
sf::Sound sound;

int audio(){


    if (!music.openFromFile("audio/music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(10.f);

    music.play();
    music.setLoop(true);
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("audio/sound.wav"))
        ms_error(22, "nie zaladowano sound.wav");

    sound.setBuffer(buffer);
    sound.setVolume(150.f);
}
